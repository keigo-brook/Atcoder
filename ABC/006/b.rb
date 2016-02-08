n = gets.to_i
a = [0, 0, 1]
for i in 3..(n-1) do
  a[i % 3] = (a[0] + a[1] + a[2]) % 10007
end
puts a[(n-1) % 3]