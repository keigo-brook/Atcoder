a, b, k, l = gets.split.map(&:to_f)

ans = 0
if l / b < a
  bn = (k / l).to_i
  ans += bn * b
  if k - bn > 0
    if a * (k - bn * l) < b
      ans += a * (k - bn*l)
    else
      ans += b
    end
  end
else
  ans = a * k
end
puts ans.to_i