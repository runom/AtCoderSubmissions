a = gets.to_i
b = gets.to_i
puts [a - b, b - a, (a + 10) - b, a - (b + 10)].map(&:abs).min