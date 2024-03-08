import heapq
import copy


def go_to_floor1(state):
    if state[-1]<8 and state[1]>0:
        if state[1]>8-state[-1]:
            new_state = [1] + [state[1] + state[-1] - 8] + [state[2]] + [state[3]] + [state[4]] + [8]
        else:
            new_state = [1] + [0] + [state[2]] + [state[3]] + [state[4]] + [state[1] + state[-1]]
        return new_state
 
def go_to_floor2(state):
    if state[5]<8 and state[2]>0:
        if state[2]>8-state[5]:
            new_state = [2] + [state[1]] + [state[2] + state[5] - 8] + [state[3]] + [state[4]] + [8]
        else:
            new_state = [2] + [state[1]] + [0] + [state[3]] + [state[4]] + [state[2] + state[5]]
        return new_state

def go_to_floor3(state):
    if state[5]<8 and state[3]>0:
        if state[3]>8-state[5]:
            new_state = [3] + [state[1]] + [state[2]] + [state[3]+state[5]-8] + [state[4]] + [8]
        else:
            new_state = [3] +  [state[1]] + [state[2]] + [0] + [state[4]] + [state[3] + state[5]]
        return new_state              

def go_to_floor4(state):
    if state[5]<8 and state[4]>0:
        if state[4]>8-state[5]:
            new_state = [4] + [state[1]] + [state[2]] + [state[3]] + [state[4]+state[5] - 8] + [8]
        else:            
            new_state = [4] +  [state[1]] + [state[2]] + [state[3]] + [0] + [state[4] + state[5]]
        return new_state


def go_to_roof(state):
    if state[5] == 0:
       return None
    else:
       new_state = [5] + [state[1]] + [state[2]] + [state[3]] + [state[4]] + [0]
       return new_state    

        


def find_children(state):

    children=[]

    floor1_state=copy.deepcopy(state)
    floor1_child=go_to_floor1(floor1_state)
    floor2_child=go_to_floor2(floor1_state)
    floor3_child=go_to_floor3(floor1_state)
    floor4_child=go_to_floor4(floor1_state)
    roof_child=go_to_roof(floor1_state)


    if roof_child!=None: 
        children.append(roof_child)
    if floor4_child!=None:
        children.append(floor4_child)
    if floor3_child!=None:
        children.append(floor3_child)    
    if floor2_child!=None:
        children.append(floor2_child)
    if floor1_child!=None:
        children.append(floor1_child)     
        
    return children


def heuristic(state, goal):
    return sum(abs(state[i] - goal[i]) for i in range(len(state)))

def a_star_search(initial_state, goal):
    open_list = [(0, initial_state)]  # Priority queue with (cost + heuristic, state)
    closed_set = set()

    while open_list:
        cost, current_state = heapq.heappop(open_list)

        if current_state == goal:
            print("Goal Found!")
            print("Goal State:", current_state)
            return

        if tuple(current_state) in closed_set:
            continue

        closed_set.add(tuple(current_state))

        for child in find_children(current_state):
            child_cost = cost + 1  # Assuming uniform cost for simplicity
            heuristic_cost = heuristic(child, goal)
            total_cost = child_cost + heuristic_cost
            heapq.heappush(open_list, (total_cost, child))

    print("Goal not found")

    
if __name__ == "__main__":
    initial_state =[0,9,12,4,7,0]
    goal_state = [5,0,0,0,0,0]
    a_star_search(initial_state, goal_state)
