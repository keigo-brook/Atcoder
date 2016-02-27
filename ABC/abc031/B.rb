l, h = gets.split.map(&:to_i)
n = gets.to_i
n.times do 
  a = gets.to_i
  if a < l
    puts l - a 
  elsif a > h
    puts (-1)
  else
    puts 0
  end
end