a, b, c = gets.split.map(&:to_i)
puts a * b * c % (1000000000 + 7)
