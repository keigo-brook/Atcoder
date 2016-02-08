n = gets.to_i
h = gets.split.map(&:to_i)
x = gets.to_i
ans = 0
for i in 0..(h.length-2)
  if x >= h[i] && x < h[i+1]
    ans = i+2
    break
  end
end
if ans == 0 && x > h[-1]
  ans = h.length+1
elsif ans == 0
  ans = 1
end
puts ans