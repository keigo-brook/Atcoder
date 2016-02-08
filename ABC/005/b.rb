n = gets.to_i
ans = 101
n.times do
  t = gets.to_i
  if t < ans
    ans = t
  end
end
puts ans