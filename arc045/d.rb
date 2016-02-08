n = gets.to_i
n21 = 2*n+1
xy = Array.new(n21) { Array.new(2) }

n21.times do |i|
    xy[i][0], xy[i][1] = gets.split(' ').map(&:to_i)
end

cax = Array.new(n21, 0)
cay = Array.new(n21, 0)

n21.times do |i|
    cax[xy[i][0]] += 1
    cay[xy[i][1]] += 1
end

n21.times do |j|
    puts "#{cax}"
    puts "#{cay}"
    if cax[xy[j][0]] % 2 == 0 || cay[xy[j][1]] %2 == 0
        puts "NG"
    else
        puts "OK"
    end
end



