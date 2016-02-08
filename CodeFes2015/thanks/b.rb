a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
c = gets.to_i
ans = []
if a.include?(c) && b.include?(c)
  a.each do |v|
    ans.push(v)
  end
  b.each do |v|
    ans.push(v)
  end
elsif a.include?(c)
  b.each do |v|
    ans.push(v)
  end
elsif b.include?(c)
  a.each do |v|
    ans.push(v)
  end
end
ans.uniq!

puts ans.length
puts ans.sort