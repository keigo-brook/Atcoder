a = gets.split(' ')
ans = ''

a.each do |aa|
    if aa == 'Left'
        ans += '< '
    elsif aa == 'Right'
        ans += '> '
    else
        ans += 'A '
    end
end
puts ans.strip