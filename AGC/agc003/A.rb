s = gets.chomp!
if (s.include?('N') && s.include?('S') && !s.include?('W') && !s.include?('E')) ||
   (!s.include?('N') && !s.include?('S') && s.include?('W') && s.include?('E')) ||
   (s.include?('N') && s.include?('S') && s.include?('W') && s.include?('E'))
  puts "Yes"
else
  puts "No"
end
