
using JuMP
using HiGHS

mutable struct LotSizingBacklogData
    n::Int #numero de periodos
    c::Array{Float64} #custo de produção
    h::Array{Float64} #custo de estoque
    p::Array{Float64} #valor da multa no per´ıodo 
    d::Array{Int64} #demandas dos clientes
end

function readData(file)
	n = 0
	c = []
	h = []
	d = []
	p = []
	for l in eachline(file)
		q = split(l, "\t")
		num = parse(Int64, q[2])
		if q[1] == "n"
			n = num
			c = [0 for i=1:n]
			h = [0 for i=1:n]
			p = [0 for i=1:n]
			d = [0 for i=1:n]
		elseif q[1] == "c"
			num = parse(Int64, q[2])
			c[num] = parse(Float64, q[3])
		elseif q[1] == "s"
			num = parse(Int64, q[2])
			h[num] = parse(Float64, q[3])
        elseif q[1] == "p"
			num = parse(Int64, q[2])
			p[num] = parse(Float64, q[3])	
		elseif q[1] == "d"
			num = parse(Int64, q[2])
			d[num] = parse(Int64, q[3])
		end
	end
	return LotSizingBacklogData(n,c,h,p,d)
end

function printSolution(data, x)
	println("Esquema de produção:")
	for i = 1: data.n
		println("No periodo $i é produzido $(value(x[i]))")
	end
	println()
end

model = Model(HiGHS.Optimizer)

set_silent(model)

file = open(ARGS[1], "r")

data = readData(file)

@variable(model, x[i=1:data.n] >= 0,Int)
@variable(model, s[i=1:data.n+1] >= 0,Int)
@variable(model, r[i=1:data.n+1] >= 0,Int)


for i=1:data.n
	@constraint(model, s[i+1] - r[i+1] == s[i] + x[i] - data.d[i] - r[i])	
end

@constraint(model, s[1] == 0)
@constraint(model, r[1] == 0)
@constraint(model, r[data.n+1] == 0)



@objective(model, Min, sum(data.c[i]*x[i] + data.h[i]*s[i+1] +data.p[i]*r[i+1] for i=1:data.n))

#print(model)

optimize!(model)

sol = objective_value(model)
println("TP1 2022043663 = ", sol)

#printSolution(data, x)

