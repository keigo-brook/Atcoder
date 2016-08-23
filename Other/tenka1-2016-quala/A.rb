# coding: utf-8
def fizzBuzz(n)
  ans = 0
  for i in 1..n
    if i % 15 != 0 && i % 5 != 0 && i % 3 != 0
      ans += i
    end
  end
  puts ans
end

fizzBuzz(100)
