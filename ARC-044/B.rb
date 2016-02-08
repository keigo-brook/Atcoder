n = gets.to_i
a = gets.split(' ').map(&:to_i)

ans = 0

a.each_with_index do |an, i|
    if a[0] == 0
        puts -1
        return
    end
    if a.select{ |e| e == 0 }.count > 1
        puts -1
        return
    end
    
    if an == 1 && i > 1
        ans += i
    end
end

puts ans
