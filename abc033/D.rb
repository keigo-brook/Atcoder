def dist(a, b)
  (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1])
end

n = gets.to_i
dp = Array.new(n)
n.times do |i|
  dp[i] = gets.split.map(&:to_i)
end
ei = 0
don = 0
tyoku= 0

for i in 0...n do 
  for j in (i+1)...n do 
    for k in (j+1)...n do
      v = [dist(dp[i], dp[j]), dist(dp[j], dp[k]), dist(dp[k], dp[i])].sort!
      cos = (v[0] + v[1] - v[2])
      if cos == 0
        tyoku += 1
      elsif cos < 0
        don += 1
      else
        ei += 1
      end
    end
  end
end
puts "#{ei} #{tyoku} #{don}"