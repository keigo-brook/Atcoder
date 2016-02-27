a = gets.to_i
b = gets.to_i

if (b > 0 && a > 0 && a > b) || (b < 0 && a < 0 && b > a)
  ans = (a * 2).abs
elsif (b > 0 && a > 0 && a < b) ||  (a < 0 && b < 0 && a > b)
  ans = (b * 2).abs
elsif b > 0 && a < 0
  ans = (-1*a*2 + b*2).abs
elsif b < 0 && a > 0
  ans = (a*2 + -1*b*2).abs
end

puts ans