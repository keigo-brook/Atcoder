$x1, $y1, $r = gets.split.map(&:to_i)
x2, y2, x3, y3 = gets.split.map(&:to_i)

def inC(x, y)
 dist(x, y) <= $r * $r
end

def dist(a, b)
  (a - $x1) * (a - $x1) + (b - $y1) * (b - $y1)
end

if inC(x2, y2) && inC(x2, y3) && inC(x3, y2) && inC(x3, y3)
  puts "YES"
  puts "NO"
elsif !inC(x2, y2) && !inC(x2, y3) && !inC(x3, y2) && !inC(x3, y3)
  if x2 <= $x1 && $x1 <= x3 && y2 <= $y1 && $y1 <= y3
    if ($x1 + $r) > x3 || ($x1 - $r) < x2 || ($y1 + $r) > y3 || ($y1 - $r) < y2
      puts "YES"
      puts "YES"
    else
      puts "NO"
      puts "YES"
    end
  else
    puts "YES"
    puts "YES"
  end
else
  puts "YES"
  puts "YES"
end
    