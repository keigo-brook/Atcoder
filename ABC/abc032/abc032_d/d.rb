N, W = gets.split.map(&:to_i)

w = Array.new(N)
v = Array.new(N)

dp = Array.new(N + 1){ Array.new(W + 1, -1) }

N.times do |i|
    v[i], w[i] = gets.split.map(&:to_i)
end

puts "#{v}"
puts "#{w}"
puts "#{dp}"
(N-1).downto(0) do |i|
    for j in 0..W
        if j < w[i]
            dp[i][j] = dp[i + 1][j]
        else
            puts "i #{i} j #{j}"
            dp[i][j] = [dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]].max
        end
    end
end
puts dp[0][W]