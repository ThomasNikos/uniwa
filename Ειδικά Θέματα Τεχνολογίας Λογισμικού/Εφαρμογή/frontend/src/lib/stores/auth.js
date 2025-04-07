import { writable } from "svelte/store";
import { browser } from "$app/environment";

export const authStore = writable(browser && JSON.parse(localStorage.getItem('auth') || 'null'));


// Update localStorage when store changes
if (browser) {
    authStore.subscribe((value) => {
        localStorage.setItem('auth', JSON.stringify(value));
    });
}

// @ts-ignore
export const setAuth = (userData) => {
    authStore.set(userData);
};

export const clearAuth = () => {
    authStore.set(null);
};