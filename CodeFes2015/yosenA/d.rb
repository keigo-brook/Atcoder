n, m = gets.split().map(&:to_i)
x = []
m.times do |i|
    x[i] = gets.to_i
    x[i] -= 1
end

train = Array.new(n, 0)
sumt = train.inject(:+)
count = 0
    rf = 0
    lf = 0
while sumt < n
    kk = ""
    n.times do |k|
        kk += "#{train[k]} "
    end
    puts kk

    m.times do |i|
        lnokori = 0
        rnokori = 0
        train[x[i]] = 1
        if i == 0
            if lf == 0
                if x[i] == 0
                    lf = 1
                    x[i] +=1
                else
                    x[i] -= 1
                end
            else
                x[i] += 1
            end
        elsif i == m-1
            if rf == 0
                x[i] += 1
                if x[i] == n-1
                    rf = 1
                end
            else
                x[i] -= 1
            end
        else
            for j in (x[i-1])..(x[i]-1)
                if train[j] == 0
                    lnokori += 1
                end
            end
            for j in (x[i]+1)..(x[i+1]-1)
                if train[j] == 0
                    rnokori += 1
                end
            end

            if lnokori > rnokori
                x[i] -= 1
            else
                x[i] += 1
            end
        end

        # end
    end
    sumt = train.inject(:+)
    count += 1
end

puts count
