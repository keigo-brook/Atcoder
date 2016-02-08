s = gets
k = gets.to_i
t = []
if s.length < k
    puts 0 
else
    for i in 0..(s.length - k - 1)
        tmp = s[i..(i + k - 1)]
        if t.include?(tmp)
            next
        else
            t.push(tmp)
        end
    end
    puts t.length
end
