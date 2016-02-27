n, m = gets.split(" ").map(&:to_i)
a = []
b = []
a = gets.split(" ").map(&:to_i)
b = gets.split(" ").map(&:to_i)

if n < m 
    puts "NO"
else
    a.sort! {|a, b| (-1) * (a <=> b) }
    b.sort! {|a, b| (-1) * (a <=> b) }
    b.each_with_index do |v, i|
        if a[i].nil? || a[i] < b[i]
            puts "NO"
            exit
        end
    end
    puts "YES"
end
