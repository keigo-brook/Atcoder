s = gets
n = gets.to_i
t = []
if s.length < n
    puts 0 
else
    for i in 0..(s.length- n - 1)
        tmp = s[i..(i + n - 1)]
        if t.include?(tmp)
            next
        else
            t.push(tmp)
        end
    end
    puts t.length
end