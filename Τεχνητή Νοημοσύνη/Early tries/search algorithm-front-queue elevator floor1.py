""" ----------------------------------------------------------------------------
******** Search Code for DFS  and other search methods
******** (expanding front only)
******** author:  AI lab
********
******** Κώδικας για α DFS και άλλες μεθόδους αναζήτησης
******** (επέκταση μετώπου μόνο)
******** Συγγραφέας: Εργαστήριο ΤΝ
"""

import copy
from collections import deque
import sys  
sys.setrecursionlimit(10**6) 

# ******** Operators
# ******** Τελεστές

  
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




""" ----------------------------------------------------------------------------
**** FRONT
**** Διαχείριση Μετώπου
"""

""" ----------------------------------------------------------------------------
** initialization of front
** Αρχικοποίηση Μετώπου
"""

def make_front(state):
    return [state]
    
""" ----------------------------------------------------------------------------
**** expanding front
**** επέκταση μετώπου    
"""

def expand_front(front, method):  
    if method=='DFS':        
        if front:
            print("Front:")
            print(front)
            node=front.pop(0)
            for child in find_children(node):     
                front.insert(0,child)
    elif method == 'BFS':
        if front:
            print("Front:")
            print(front)
            front=deque(front)
            node = front.popleft()  # Use popleft() to remove the leftmost element (front of the queue)
            for child in find_children(node):
                front.append(child) 
           
    return front


""" ----------------------------------------------------------------------------
**** QUEUE
**** Διαχείριση ουράς
"""

""" ----------------------------------------------------------------------------
** initialization of queue
** Αρχικοποίηση ουράς
"""

def make_queue(state):
    return [[state]]

""" ----------------------------------------------------------------------------
**** expanding queue
**** επέκταση ουράς
"""

def extend_queue(queue, method):
    if method=='DFS':
        print("Queue:")
        print(queue)
        node=queue.pop(0)
        queue_copy=copy.deepcopy(queue)
        children=find_children(node[-1])
        for child in children:
            path=copy.deepcopy(node)
            path.append(child)
            queue_copy.insert(0,path)
    elif method == 'BFS':
        print("Queue:")
        print(queue)
        queue=deque(queue)
        node =queue.popleft()  # Use popleft() to remove the leftmost element (front of the queue)
        queue_copy = copy.deepcopy(queue)
        children = find_children(node[-1])
        for child in children:
           path = copy.deepcopy(node)
           path.append(child)
           queue_copy.append(path)
        
    #elif method=='BestFS':
    #else: "other methods to be added" 
    
    return queue_copy


""" ----------------------------------------------------------------------------
**** Problem depending functions
**** ο κόσμος του προβλήματος (αν απαιτείται) και υπόλοιπες συναρτήσεις σχετικές με το πρόβλημα

  #### to be  added ####
"""

""" ----------------------------------------------------------------------------
**** Basic recursive function to create search tree (recursive tree expansion)
**** Βασική αναδρομική συνάρτηση για δημιουργία δέντρου αναζήτησης (αναδρομική επέκταση δέντρου)
"""

def find_solution(front, queue, closed, goal, method,steps=1):
#def find_solution(front, queue, closed, method):
       
    if not front:
        print('_NO_SOLUTION_FOUND_')
    
    elif front[0] in closed:
        front=deque(front)
        new_front=copy.deepcopy(front)
        new_front.popleft()
        new_queue=copy.deepcopy(queue)
        new_queue.popleft()
        find_solution(new_front, new_queue, closed, goal, method,steps+1)
        #find_solution(new_front, new_queue, closed, method)
    
    #elif is_goal_state(front[0]):
    elif front[0]==goal:
        print('_GOAL_FOUND_')
        #print(front[0])
        print("\nSteps : ",steps)
        print(queue[0])
        
    else:
        closed.append(front[0])
        front_copy=copy.deepcopy(front)
        front_children=expand_front(front_copy, method)
        queue_copy=copy.deepcopy(queue)
        queue_children=extend_queue(queue_copy, method)
        closed_copy=copy.deepcopy(closed)
        find_solution(front_children, queue_children, closed_copy, goal, method,steps+1)
        #find_solution(front_children, queue_children, closed_copy, method)
        
        
        
"""" ----------------------------------------------------------------------------
** Executing the code
** κλήση εκτέλεσης κώδικα
"""
           
def main():
    
    initial_state = [0, 9, 4, 12, 7, 0]
    goal = [5, 0, 0, 0, 0, 0]
    method= 'DFS'
    
    """ ----------------------------------------------------------------------------
    **** starting search
    **** έναρξη αναζήτησης
    """
    
    print('____BEGIN__SEARCHING____')
    find_solution(make_front(initial_state), make_queue(initial_state), [], goal, method)
    #find_solution(make_front(initial_state), make_queue(initial_state), [], method)

    
    
if __name__ == "__main__":
    main()
