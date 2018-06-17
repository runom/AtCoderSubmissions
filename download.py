#!/usr/bin/env python
# -*- coding: utf-8 -*-

import json
import urllib.request
import re
import lxml.html
import os
import sys
import time

user = 'mino'

with urllib.request.urlopen(f"https://kenkoooo.com/atcoder/atcoder-api/results?user={user}") as data:
    results = json.loads(data.read())

results.sort(key=lambda x:x['epoch_second'])

lang2ext = {'C++':'cpp', 'Python':'py', 'Ruby':'rb', 'Text':'txt'}

for i, result in enumerate(results):
    sys.stdout.write(f'\r\033[K{i+1} / {len(results)}')
    sys.stdout.flush()

    if result['result'] == 'AC':
        url = f"https://beta.atcoder.jp/contests/{result['contest_id']}/submissions/{result['id']}"

        lang = re.sub('\d* \(.*\)', '', result['language'])

        if lang not in lang2ext:
            print(f"Enter the file extension of {lang}.")
            lang2ext[lang] = input()

        ext = lang2ext[lang]
        path = f"AtCoder/{result['contest_id']}/{result['problem_id']}.{ext}"

        with urllib.request.urlopen(url) as f:
            dom = lxml.html.fromstring(f.read())            
        source = dom.xpath('id("submission-code")/text()')[0]

        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, 'w') as f:
            f.write(source)

        time.sleep(1)

print()
