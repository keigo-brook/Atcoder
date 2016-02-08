n, m = gets.split(" ").map(&:to_i)
a = []
a = gets.split(" ").map(&:to_i).inject(Hash.new(0)){|h, key| h[key] += 1; h}.max { |a, b| a[1] <=> b[1] }
if h.last > a.size / 2
    puts h.first
else
    puts "?"
end

