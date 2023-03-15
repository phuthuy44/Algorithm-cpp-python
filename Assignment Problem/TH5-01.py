import fileinput 
#read input from file 
line = []
for line in fileinput.input("E:/Phuong Vy/Algorithm-cpp-python/Assignment Problem/Assignmenta.txt"):
    line.append(line.strip())
#extract number of workers and jobs
n = int(line[0])
#initialize array of jobs and workers
workers = []
jobs = []
#populate array of workers and jobs lists with cost matrix 
for i in range(1,n+1):
    row = list(map(int,line[i].split()))
    workers.append(row)
for i in range(n+1,2*n+1):
    row = list(map(int,line[i].split()))
    jobs.append(row)
#initialize solution matrix with zeros
matrix =[[0 for j in range(n)]for i in range(n)]
for i in range(n):
    max_cost = float("-inf")
    max_cost_index = -1
    for j in range(n):
        if workers[i][j] > max_cost:
            max_cost = workers[i][j]
            max_cost_index = j
     #assign the workers to the job with the max cost
    # matrix[i][max_cost_index] = 
    jobs[workers[i]]=i
total_cost =0 
for i in range(n):
     total_cost += matrix[i][workers[i]]
     print("Workers {} assigned to job {} with cost{}\n".format(i+1,workers[i]+1,matrix[i][workers[i]]))
for i in range(n):
     for j in range(n):
          print(matrix[i][j],end=" ")
     print()
print("Total cost: ",total_cost)