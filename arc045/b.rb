n, m = gets.split(' ').map(&:to_i)
area = Array.new(m).map{Array.new(2)}
ca = Array.new(n).map{Array.new(1,0)}

m.times do |i|
    area[i][0], area[i][1] = gets.split(' ').map(&:to_i)
end

ca.each do |c|
    c[1] = Array.new()
end
m.times do |i|
    for j in (area[i][0]-1)..(area[i][1]-1)
        ca[j][0] += 1
        ca[j][1].push(i+1)
    end
end

ccaa = []
ccaaa = []
ca.each_with_index do |c, i|
    if c[0] > 1 
        ccaaa.push(i)
        c[1].each do |cc|
            ccaa.push(cc)
        end
    end
end

ansc = 0
ansa = []
ccaa.uniq.each do |p|
    count = 0
    ccaaa.each do |pp|
        if ca[pp][1].include?(p)
            count += 1
        end
    end
    if count > area[p-1][1] - area[p-1][0]
        ansc +=1
        ansa.push(p)
    end
end

puts ansc
puts ansa