s1 = gets.split('')
s2 = gets.split('')
a = %w(a t c o d e r @)
s1.each_with_index do |s, i|
  if (s == '@' && !a.include?(s2[i])) || (s2[i] == '@' && !a.include?(s)) || (s2[i] != '@' && s != '@' && s2[i] != s)
    puts 'You will lose'
    exit
  end
end
puts 'You can win'