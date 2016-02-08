n = gets.to_i
a = []
b = []
n.times do
  s = gets.chomp
  if (t = a.index(s)) != nil
    b[t] += 1
  else
    a.push(s)
    b.push(1)
  end
end
max = 0
maxi = 0
b.each_with_index do |c, i|
  if c > max
    max = c
    maxi = i
  end
end
puts a[maxi]