m = gets.to_i
ans = 0
if m < 100
  ans = 0
elsif m <= 5000
  ans = m / 100
elsif  m <= 30000
  ans = m / 1000 + 50
elsif m <= 70000
  ans = (m / 1000 - 30) / 5 + 80
else
  ans = 89
end
puts sprintf('%02d', ans)