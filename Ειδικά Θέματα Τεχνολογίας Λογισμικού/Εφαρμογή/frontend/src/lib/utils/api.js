import { get } from "svelte/store";
import { authStore } from "$lib/stores/auth";
import { clearAuth } from "$lib/stores/auth";
import { goto } from "$app/navigation";



// @ts-ignore
export async function authenticatedFetch(url , options ={}) {
    const auth = get(authStore);
    console.log(auth);

    if(!auth?.token){
        goto('/');
        throw new Error('No authentication token available');
    }

    const headers = {
        'Authorization': `Bearer ${auth.token}`,
        'Content-Type': 'application/json',
        // @ts-ignore
        ...options.headers
    }

    const response = await fetch(url,{
        ...options,
        headers
    });

    if (response.status === 401) {
        // Token expired or invalid
        clearAuth();
        throw new Error('Authentication expired');
    }
    
    return response;
}