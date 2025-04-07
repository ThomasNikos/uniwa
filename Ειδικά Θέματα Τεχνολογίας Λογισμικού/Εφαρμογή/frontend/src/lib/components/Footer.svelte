<!-- Footer.svelte -->
<script>
    import {  Facebook , Mail } from 'lucide-svelte';
    import { Instagram } from 'lucide-svelte';
    import { Twitter } from 'lucide-svelte';
    import logo from '$lib/images/logo.png';

  </script>
  
  <footer class="bg-cyan-900 text-white py-16">
    <div class="container mx-auto px-4">
      <div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-8">
        <!-- Logo Section -->
        <div class="flex flex-col items-center md:items-start">
          <img src={logo} alt="Barbershop Logo" class="h-24 w-auto mb-4" />
          <p class="text-sm text-gray-300">EST. 2024</p>
        </div>
  
        <!-- Sitemap Section -->
        <div>
          <h3 class="text-xl font-semibold mb-4">Sitemap</h3>
          <nav class="flex flex-col space-y-2">
            <a href="/" class="text-yellow-500 hover:text-yellow-400">Home</a>
            <a href="/" class="hover:text-yellow-400">About us</a>
            <div class="relative group">
              <a href="/" class="hover:text-yellow-400">Reviews</a>
            </div>
            <div class="relative group">
              <a href="#gaol" class="hover:text-yellow-400">Our Goal</a>
            </div>
            <a href="/" class="hover:text-yellow-400">Blog</a>
            <a href="/auth/register" class="hover:text-yellow-400">Sign up</a>
          </nav>
        </div>
  
        <!-- Social Media Section -->
        <div>
          <h3 class="text-xl font-semibold mb-4">Social Media</h3>
          <div class="flex space-x-4">
            <a href="/" class="hover:text-yellow-400">
                <Instagram class="w-6 h-6"/>
            </a>
            <a href="/" class="hover:text-yellow-400">
              <Facebook class="w-6 h-6" />
            </a>
            <a href="/" class="hover:text-yellow-400">
                <Twitter class = "w-6 h-6" />
            </a>
            <a href="/" class="hover:text-yellow-400">
              <Mail class="w-6 h-6" />
            </a>
          </div>
        </div>
  
        <!-- Contact Section -->
        <div>
          <h3 class="text-xl font-semibold mb-4">Contact</h3>
          <div class="space-y-4">
            <div class="flex flex-col">
              <p class="font-medium">Location 1</p>
              <p class="text-gray-300">217 Main Street</p>
              <p class="text-gray-300">City, State 12345</p>
              <p class="text-yellow-400">+1 234 567 8900</p>
            </div>
          </div>
        </div>
      </div>
  
      <!-- Bottom Section with Privacy Policy -->
      <div class="mt-12 pt-4 border-t border-gray-600 text-center">
        <a href="/privacy" class="text-sm text-gray-400 hover:text-yellow-400">
          Privacy Policy
        </a>
      </div>
    </div>
  </footer>