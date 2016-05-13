N = gets.to_i
s = []
N.times do
  s.push(gets.chomp!)
end

N.times do |i|
  N.times do |j|
    print s[N - j - 1][i]
  end
  puts ""
end
