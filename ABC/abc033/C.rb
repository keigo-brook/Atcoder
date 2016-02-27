s = gets
b = s[0].to_i
ans = 0
for i in 1..s.size do
  if s[i] == '*'
    b *= s[i+1].to_i
    i += 2
  elsif s[i] == '+'
    if b != 0
      b = 0
      ans += 1
    end
    b += s[i+1].to_i
  end
end
ans += 1 if b != 0
puts ans