n = gets.to_i
a = gets.split().map(&:to_i)

s = []
s[0] = 0

for i in 1..n do
    s[i] = s[i-1]*2 + a[i-1]
end

puts s.last