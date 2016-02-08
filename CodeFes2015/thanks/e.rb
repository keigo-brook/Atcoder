n = gets.to_i

n.times do
  s, t = gets.split
  s1 = s.split('')
  t1 = t.split('')
  c = 0
  i = 0
  while i < s1.length
    if t1[c] == s1[i]
      c += 1
    elsif c > 0 && t1.include?(s1[i])
      c = 0
      if s1[i] == t1[0]
        i -= 1
      end
    end
    if c == t.length
      break
    end
    i += 1
  end
  if c == t.length || s.include?(t)
    puts "YES"
  else
    puts "NO"
  end
end

