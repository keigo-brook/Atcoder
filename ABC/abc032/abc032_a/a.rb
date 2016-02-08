a = gets.to_i
b = gets.to_i
n = gets.to_i
ans = n
loop do
    if ans % a == 0 && ans % b == 0
        break
    end
    ans += 1
end
puts ans