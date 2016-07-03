# do wbwbwwbwbwbw
# re wbwwbwbwbwwb
# mi wwbwbwbwwbwb
# fa wbwbwbwwbwbw
# so wbwbwwbwbwwb
# la wbwwbwbwwbwb
# si wwbwbwwbwbwb 

ll = ["wbwbwwbwbwbw","wbwwbwbwbwwb","wwbwbwbwwbwb","wbwbwbwwbwbw","wbwbwwbwbwwb","wbwwbwbwwbwb","wwbwbwwbwbwb" ]
s = gets.chomp.split('')
s.pop while s.size > 12
t = s.join.downcase

ll.size.times do |i|
  # puts "#{ll[i]}"
  # puts "#{t}"
  if ll[i] == t
    case i
    when 0
      puts "Do"
    when 1
      puts "Re"
    when 2
      puts "Mi"
    when 3
      puts "Fa"
    when 4
      puts "So"
    when 5
      puts "La"
    when 6
      puts "Si"
    end
  end
end
