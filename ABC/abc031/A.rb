a, d = gets.split.map(&:to_i)
if (a + 1)*d > a*(d + 1)
  puts (a+1)*d
else
  puts a*(d+1)
end