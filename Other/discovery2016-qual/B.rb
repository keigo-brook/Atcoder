n = gets.to_i
a = gets.split.map(&:to_i)
ma = a.max
b = Array.new(ma+1, 0)
c = Array.new(ma+1, 0)

a.each_with_index do |v, i|
  c[v] = i if c[v] == 0
  b[v] = i
end


ans = 1
maxi = 0
mini = n + 1
until b.uniq.size == 1
  max = -1
  min = n + 1
  for i in maxi..ma
      # puts "#{i} #{c[i]} #{max}"
    next if b[i] == 0
    if c[i] > max
      max = b[i]
      min = c[i+1]
      maxi = i
      b[i] = 0
    elsif b[i] < max || c[i] > min
      ans += 1
      # puts "n"
      break
    elsif i == ma
      ans += 1
    end
  end
end
puts ans