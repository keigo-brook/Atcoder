l, x, y, s, d = gets.split.map(&:to_f)

sei = 0
if s <= d
  sei = d - s
else
  sei = (l - s + d) % l
end

rv = 0
if s <= d
  rv = (l + s - d) % l
else
  rv = s - d
end

ans = 1e15
if x - y < 0
  ans = [ans, (rv / (x - y).abs)].min
elsif x - y > 0
  ans = [ans, (sei / (x - y))].min
end

if s == d
  ans = 0
end

ans = [ans, (sei / (x + y))].min

puts ans