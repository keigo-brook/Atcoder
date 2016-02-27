n = gets.to_i
k = gets.split.map(&:to_i)
ans = [k[0]]

(n-1).times do |i|
    if ans[-1] < k[i]
        a = k[i]
    else
        if i == n - 2
            a = k[i]
        else
            if k[i + 1] > k[i]
                a = k[i]
            else
                a = k[i + 1]
            end 
        end   
    end
    ans.push(a)
end
puts ans.join(' ')
