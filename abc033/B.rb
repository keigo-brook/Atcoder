n = gets.to_i
a = {}
n.times do 
  s = gets.split
  a[s[0]] = s[1].to_i
end
sum = 0
a.each{|v| sum += v[1] }
a.each do |v|
  if v[1] > sum/2
    puts v[0] 
    exit
  end
end
puts 'atcoder'