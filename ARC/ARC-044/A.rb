def prime?(n)
    if n<2
        puts "Not Prime"
        return true
    end

    if n == 2
        puts 'Prime'
        return
    elsif n == 3
        puts 'Prime'
        return
    elsif n == 5
        puts 'Prime'
        return
    end

    if n%2 != 0 && n%3 != 0 && n%5 != 0 
        puts 'Prime'
        return
    end

    (2..Math.sqrt(n)).each do |x|
        if n%x ==0
            puts 'Not Prime'
            return
        end
    end

    puts 'Not Prime'
end


n = gets.to_i
prime?(n)



