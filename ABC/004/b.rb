a = []
4.times do
  a.push(gets.split)
end
for i in 0..3
  for j in 0..1
    tmp = a[3-i][3-j]
    a[3-i][3-j] = a[i][j]
    a[i][j] = tmp
  end
end

puts "#{a[0].join(' ')}\n#{a[1].join(' ')}\n#{a[2].join(' ')}\n#{a[3].join(' ')}"