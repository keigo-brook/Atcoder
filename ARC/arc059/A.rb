n = gets.to_i
a = gets.split.map(&:to_i)
ave = (a.inject(0.0){ |r, i| r += i }/a.size).ceil
ans = 0
a.each do |i|
  ans += (i - ave) * (i - ave)
end
puts ans
