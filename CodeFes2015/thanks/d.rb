n = gets.to_i
s = []
n.times do
  s.push(gets.to_i)
end
sumn = s.inject{|sum, n| sum + n}
m = gets.to_i


dp = []
n.times do |v|
  a = [n-1, sumn-s[v]]
  dp.push(a)
end

ii = []
m.times do
  info = gets.split.map(&:to_i)
  f = false
  if info[0] == 0
    dp[info[1]-1][0] -= 1
    dp[info[1]-1][1] -= s[info[2]-1]
    ii.push(info)
  else
    ii.each do |v|
      if (v[1] == info[1]) && (v[2] == info[2])
        puts "#{s[v[2]-1]} #{s[v[2]-1]}"
        f = true
        break
      end
    end
    unless f
      if dp[info[1]-1][0] < 2
        min = dp[info[1]-1][1]
      elsif dp[info[1]-1][1] >= 100
        min = dp[info[1]-1][1] - (dp[info[1]-1][0]-1)*100
        min = 0 if min < 0
      else
        min = 0
      end
      if dp[info[1]-1][1] >= 100
        max = 100
      else
        max = dp[info[1]-1][1]
      end
      puts "#{min} #{max}"
    end
  end
end
