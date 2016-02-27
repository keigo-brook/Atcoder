n = gets.to_i
a = []
b = []
n.times do |i| 
    s, c = gets.split(" ").map(&:to_i)
    if s > a[0] && s < b[0]
        b[0] += c 
    elsif s < a[0]
        a.unshift(s)
        if a[0] + c > a[1]
            a.delete_at(1)
            c -= a[1] - a[0]
        else 
            b.unshift(a[0]+c)
        end
        
        if (a[0] == a[1])

    
end
