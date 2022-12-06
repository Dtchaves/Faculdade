function demand(p,u1,u2,e,bt,r,grida)
  function utilid(a)
    if e[1]-a*p>0
      return u1(e[1]-p*a) + bt*u2(e[2]+r*a)
    else 
      return -10^(10)
    end
  end
  u_matrix=[utilid(a) for a in grida]
  a_otimo=grida[argmax(u_matrix)]
return a_otimo
end

function exc_demand(p,u11,u12,u21,u22,e1,e2,bt1,bt2,r,grida)
a1=demand(p, u11, u12, e1, bt1, r, grida)
a2=demand(p, u21, u22, e2, bt2, r, grida)
return a1+a2-1
end

function prec_max(u1,u2,e,bt,r,precis)
umg1=1/precis*(u1(e[1]+precis)-u1(e[1]))
umg2=1/precis*(u2(e[2]+precis)-u2(e[2]))
return r*bt*umg2/umg1
end

println("Funções demanda, excesso de demanda e preço inicial executadas com sucesso")