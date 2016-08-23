a, b = gets.split.map(&:to_i)

if a < 0 && b < 0 && ((a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1) )
  puts "Negative"
elsif a <= 0 && b >= 0
  puts "Zero"
else
  puts "Positive"
end
