n, t = gets.split().map(&:to_i)
a = []
b = []
n.times do |i|
    a[i], b[i] = gets.split().map(&:to_i)
end

sumb = b.inject(:+)
suma = a.inject(:+)
if sumb > t    
    puts -1
    exit
elsif suma < t
    puts 0
    exit
else
    diffab = []
    n.times do |i|
        diffab[i] = a[i] - b[i]
    end
    diffab.sort! {|a, b| (-1) * (a <=> b) }
    count = 0
    currentsum = suma
    while currentsum > t 
        currentsum -= diffab[count]
        count += 1
    end
    puts count
end