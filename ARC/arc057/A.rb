a, k = gets.split.map(&:to_i)
t = a
d = 0
if k == 0
  puts 20_00000000000 - a
  exit
end
loop do
  t += 1 + k * t
  if t >= 20_00000000000
    puts d + 1
    exit
  end
  d += 1
end
