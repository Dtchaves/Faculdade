function price(u11,u12,u21,u22,e1,e2,bt1,bt2,r,grida,precis)
    p1=prec_max(u11, u12, e1, bt1, r, precis)
    p2=prec_max(u21, u22, e2, bt2, r, precis)
    ngp=max(p1,p2)
    gridp=precis:precis:ngp
    abs_exc_dem(preco)=abs(exc_demand(preco,u11,u12,u21,u22,e1,e2,bt1,bt2,r,grida))
    erro_exc_dem=[abs_exc_dem(p) for p in gridp]
    eq=gridp[argmin(erro_exc_dem)]
    a1=demand(eq, u11, u12, e1, bt1, r, grida)
    a2=demand(eq, u21, u22, e2, bt2, r, grida)
    erro=minimum(erro_exc_dem)
    return [eq,a1,a2,erro]
  end
  println("Função de preço executada com sucesso")