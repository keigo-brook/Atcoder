n, k = gets.split.map(&:to_i)
s = []
max = 0
m = 0
n.times do
    s.push(gets.to_i)
    if s[-1] == 0
        max = n
        break
    end
 
    if m == 0 || m == nil
        m = s.inject(:*)
    else
        m *= s[-1]
    end
 
    while m.to_i > k
        t = s.shift
        if t.to_i != 0 && m.to_i != 0
            m /= t
        else
            m = s.inject(:*)
        end
    end
 
    if s.length > max
        max = s.length
    end
end
puts max